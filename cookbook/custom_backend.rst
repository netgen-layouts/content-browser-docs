Implementing a custom backend
=============================

Implementing a custom backend is a way to add support for your CMS of choice
to the content browser.

The concept of a backend revolves around the concept of locations and items.
Locations are comparable to folders in a file system, while items are comparable
to files. The location is used to build the tree structure that holds the items,
and items are what is actually selectable in the content browser dialogue. Types
of items are identified by their string identifier and every backend needs to
work with and return only one item type.

When implementing a backend and all its required services, it is left up to you
to define whether some locations can also be items, (like in Ibexa CMS, where
all locations in a tree are selectable), or not (like in Sylius, where locations
are built from Sylius taxons and are not selectable), or some other combination
(like in Netgen Tags, where the root location is a virtual one and thus not
selectable, while all other are).

Items need to implement ``Netgen\ContentBrowser\Item\ItemInterface`` while
locations need to implement ``Netgen\ContentBrowser\Item\LocationInterface``.
When a location is also an item, it needs to implement both
``LocationInterface`` and ``ItemInterface``.

Implementing a backend involves the following:

* Configuring and enabling your new item type
* Creating a Symfony service implementing ``Netgen\ContentBrowser\Backend\BackendInterface``
* Creating objects implementing ``ItemInterface`` and ``LocationInterface``
  which will be returned by the methods from the backend service
* Creating and configuring the templates used to render the columns or creating
  a Symfony service implementing
  ``Netgen\ContentBrowser\Item\ColumnProvider\ColumnValueProviderInterface`` for
  every column you add that's not using a template for rendering

Configuring and enabling your new item type
-------------------------------------------

Once you decide on your new item type identifier (in these examples, we will use
``my_item_type``), enabling it inside Content Browser is done with the following
minimum configuration, which defines the item human readable name, the template
used to render the item preview and a list of columns:

.. code-block:: yaml

    netgen_content_browser:
        item_types:
            my_item_type:
                name: item_types.my_item_type # Will be translated with "ngcb" catalog
                preview:
                    template: '@App/ngcb/my_item_type.html.twig'
                columns:
                    # At least a "name" column must exist
                    name:
                        name: columns.name # Will be translated with "ngcb" catalog
                        value_provider: name # Using a built in "name" value provider
                default_columns:
                    - name

For the list of all available configuration options, take a look at the
:doc:`configuration reference </reference/configuration>`.

Creating a Symfony service for the backend
------------------------------------------

Every item type needs to have a Symfony service called backend. Backend's job is
to hook into the CMS and return the data from the CMS needed to build locations
and items. Backend must only return the items of a single type, the one it is
registered for.

Every backend needs to implement ``Netgen\ContentBrowser\Backend\BackendInterface``,
which defines the number of methods used by the user interface to fetch the
locations and items. Most of these methods are straightforward. They either
return a list of locations/items under specified location or with the specified
name, or a single location/item with provided ID.

``getSections`` method should return a list of ``LocationInterface`` objects
that will act as root locations of different sections of the location tree.
For example, Ibexa specific backend would return three ``LocationInterface``
objects here, the one representing "Home" Ibexa location, the one representing
"Media" Ibexa location and the one representing "Users" Ibexa location.

Once implemented, backend needs to be registered in Symfony DIC and connected to
the item type by using ``netgen_content_browser.backend`` tag:

.. code-block:: yaml

    app.content_browser.backend.my_item_type:
        class: App\ContentBrowser\Backend\MyItemTypeBackend
        tags:
            -  { name: netgen_content_browser.backend, item_type: my_item_type }

.. note:: yaml

    If you are using autoconfiguration in your Symfony project on PHP 8.1, you
    don't have to manually create a service configuration in your config.
    Instead, you can use a PHP 8 attribute to mark the backend class as such:

    .. code-block:: php

        <?php

        declare(strict_types=1);

        namespace App\ContentBrowser\Backend;

        use Netgen\ContentBrowser\Attribute\AsBackend;
        use Netgen\ContentBrowser\Backend\BackendInterface;

        #[AsBackend('my_item_type')]
        final class MyItemTypeBackend implements BackendInterface
        {
            ...
        }

Creating ``ItemInterface`` and ``LocationInterface`` objects
------------------------------------------------------------

As already mentioned, backend needs to return objects implementing
``Netgen\ContentBrowser\Item\LocationInterface`` and
``Netgen\ContentBrowser\Item\ItemInterface``, that represent Content Browser
locations and items, respectively. It is up to you to implement these objects,
either by building them directly in the backend, using a dedicated service to
build them or in some other way you find appropriate. ``ItemInterface`` object
will be injected in all templates (either when rendering a preview of an item or
a single column), so make sure that it contains any data that you will need to
render the templates.

Creating a preview template for the item
----------------------------------------

As already mentioned, you can enable a preview of your items with the following
configuration:

.. code-block:: yaml

    netgen_content_browser:
        my_item_type:
            preview:
                template: '@App/ngcb/my_item_type.html.twig'

Creating this template is a simple task. The template receives the item in
question in an ``item`` variable, which you can use to render the template.

Implementing columns rendered via templates
-------------------------------------------

Content Browser allows you to implement your custom columns by specifying a
template that will be used to render the cell data in the column.

To enable this behaviour, simply specify that a template should be used in your
column definition:

.. code-block:: yaml

    netgen_content_browser:
        my_item_type:
            columns:
                column_one:
                    name: columns.my_item_type.column_one
                    template: '@App/ngcb/my_item_type/column_one.html.twig'

Just as with a preview template, creating this template is a simple task. Again,
the template receives the item in question in an ``item`` variable, which you
can use to render the template.

Implementing columns rendered via column value providers
--------------------------------------------------------

If rendering a column via Twig template is not suitable for you, you can use a
separate Symfony service to render the cell data of a column.

To create the service, you need to implement
``Netgen\ContentBrowser\Item\ColumnProvider\ColumnValueProviderInterface``
interface. This interface has a single ``getValue`` method which receives the
item in question and should return a value that will be displayed inside the
cell.

Once you create the service, register it in Symfony DIC, tag it with
``netgen_content_browser.column_value_provider`` tag and attach a unique
identifier to the tag:

.. code-block:: yaml

    app.content_browser.template_value_provider.my_item_type.column_two:
        class: App\ContentBrowser\ColumnValueProvider\MyItemType\ColumnTwo
        tags:
            - { name: netgen_content_browser.column_value_provider, identifier: my_item_type\column_two }

.. note:: yaml

    If you are using autoconfiguration in your Symfony project on PHP 8.1, you
    don't have to manually create a service configuration in your config.
    Instead, you can use a PHP 8 attribute to mark the value provider class
    as such:

    .. code-block:: php

        <?php

        declare(strict_types=1);

        namespace App\ContentBrowser\ColumnValueProvider\MyItemType;

        use Netgen\ContentBrowser\Attribute\AsColumnValueProvider;
        use Netgen\ContentBrowser\Item\ColumnProvider\ColumnValueProviderInterface;

        #[AsColumnValueProvider('my_item_type\column_two')]
        final class ColumnTwo implements ColumnValueProviderInterface
        {
            ...
        }

After that, you simply need to reference the identifier of the value provider in
column definition:

.. code-block:: yaml

    netgen_content_browser:
        my_item_type:
            columns:
                column_two:
                    name: columns.my_item_type.column_two
                    value_provider: my_item_type\column_two
