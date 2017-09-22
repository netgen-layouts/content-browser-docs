Symfony dependency injection tags
=================================

The following lists all dependency injection tags and their usage available
in Netgen Content Browser:

``netgen_content_browser.backend``
----------------------------------

**Purpose**: Adds a new backend to the system

A backend is a service that provides methods to load the list of items and
locations in Content Browser interface. A backend needs to implement
``Netgen\ContentBrowser\Backend\BackendInterface`` interface.

When registering a new backend, you need to use the ``item_type`` attribute in
the tag to specify the item type the backend is used for:

.. code-block:: yaml

    app.content_browser.my_backend:
        class: AppBundle\ContentBrowser\MyBackend
        tags:
            - { name: netgen_content_browser.backend, item_type: my_backend }

``netgen_content_browser.column_value_provider``
------------------------------------------------

**Purpose**: Adds a new column value provider for a single item column

A column value provider is a service that provides a value to a column displayed
in Content Browser interface for a specific item. Column value provider needs to
implement
``Netgen\ContentBrowser\Item\ColumnProvider\ColumnValueProviderInterface``
interface.

When registering a new column value provider, you need to use the ``identifier``
attribute in the tag to attach a unique identifier to the provider:

.. code-block:: yaml

    app.content_browser.my_item.custom_column:
        class: AppBundle\ContentBrowser\MyItem\CustomColumn
        tags:
            - { name: netgen_content_browser.column_value_provider, identifier: my_item\custom_column }
