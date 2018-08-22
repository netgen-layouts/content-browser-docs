Item type configuration
=======================

Configuration for each item type can be configured separately and can be
accessed from Symfony DIC with the service name
``netgen_content_browser.config.<item_type>`` where ``<item_type>`` should be
replaced with the actual identifier of your item type.

``name``
--------

This is the human readable name of your item type. You can use a translation
placeholder here, which will be translated with ``ngcb`` catalog.

**type**: ``string``, **required**: Yes, **example**: ``item_types.my_item_type``

``min_selected``
----------------

This is the number of items that needs to be selected at minimum to be able to
close the selection dialog.

Set this to ``0`` to disable the limit. This configuration can be overridden when
calling the dialog.

**type**: ``int``, **required**: No, **default**: ``1``

``max_selected``
----------------

This is the number of items that needs to be selected at maximum to be able to
close the selection dialog.

Set this to ``0`` to disable the limit. This configuration can be overridden when
calling the dialog.

**type**: ``int``, **required**: No, **default**: ``0``

``parameters``
--------------

With this, you can transfer a custom list of parameters to the item configuration,
together with all other configuration values described in this document.

**type**: ``array``, **required**: No, **default**: ``[]``

``tree``
--------

``enabled``
~~~~~~~~~~~

Controls if the tree panel will be displayed or not.

This configuration can be overridden when calling the dialog.

**type**: ``bool``, **required**: No, **default**: ``true``

``search``
----------

``enabled``
~~~~~~~~~~~

Controls if the search panel will be displayed or not.

This configuration can be overridden when calling the dialog.

**type**: ``bool``, **required**: No, **default**: ``true``

``preview``
-----------

``enabled``
~~~~~~~~~~~

Controls if the preview panel will be displayed or not.

This configuration can be overridden when calling the dialog.

**type**: ``bool``, **required**: No, **default**: ``true``

``template``
~~~~~~~~~~~~

Specifies the template that will be used to render the preview panel.

**type**: ``string``, **required**: Yes, **example**: ``@App/ngcb/my_item_type.html.twig``

``columns``
-----------

Specifies the list of columns that are available for the item type.

At least a column with identifier ``name`` must exist and either ``template``
or ``value_provider`` configuration must be specified for each of the columns.

``name``
~~~~~~~~

This is the human readable name of your column. You can use a translation
placeholder here, which will be translated with ``ngcb`` catalog.

**type**: ``string``, **required**: Yes, **example**: ``columns.my_item_type.some_column``

``template``
~~~~~~~~~~~~

Specifies the template that will be used to render the cell in the column.

**type**: ``string``, **required**: No, **example**: ``@App/ngcb/my_item_type/some_column.html.twig``

``value_provider``
~~~~~~~~~~~~~~~~~~

Specifies the identifier of a value provider that will be used to provide the
cell value.

**type**: ``string``, **required**: No, **example**: ``my_item_type\some_column``

``default_columns``
-------------------

Specifies the list of columns that will be shown when the dialog is first opened.

**type**: ``array``, **required**: Yes, **example**: ``['name', 'other_column']``
