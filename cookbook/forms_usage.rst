Usage in Symfony forms
======================

Netgen Content Browser supports calling the browser from Symfony forms. To
facilitate this, three custom Symfony form types have been implemented:

* Single content browser type
* Multiple content browser type
* Dynamic content browser type

.. include:: usage_requirements.rst.inc

Single content browser type
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Single content browser type allows you to select a single item of a predefined
item type.

Form type class
^^^^^^^^^^^^^^^

``Netgen\ContentBrowser\Form\Type\ContentBrowserType``

Available options
^^^^^^^^^^^^^^^^^

* ``item_type``

    This option defines which item type will the browser select

    **type**: ``string``, **required**: Yes

Other options
^^^^^^^^^^^^^

Parent of this type is the Symfony ``TextType`` type, so any options available
in that type can be used in this type too.

Multiple content browser type
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Multiple content browser type allows you to select one or more items of a
predefined item type.

Form type class
^^^^^^^^^^^^^^^

``Netgen\ContentBrowser\Form\Type\ContentBrowserMultipleType``

Available options
^^^^^^^^^^^^^^^^^

* ``item_type``

    This option defines which item type will the browser select

    **type**: ``string``, **required**: Yes

* ``min``

    This option defines how many items must at least be selected before the
    dialog can be closed. Use ``null`` to disable the limit.

    **type**: ``int``, **required**: No, **default value**: ``null``

* ``min``

    This option defines how many items must at maximum be selected for dialog to
    be closed. Use ``null`` to disable the limit.

    **type**: ``int``, **required**: No, **default value**: ``null``

Other options
^^^^^^^^^^^^^

Parent of this type is the Symfony ``CollectionType`` type, so any options
available in that type can be used in this type too.

Dynamic content browser type
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Dynamic content browser type allows you to select a single item, however, in
contrast to ``ContentBrowserType`` type, this type allows you to select the item
type before calling the dialog.

This type is the composite one, meaning it is constructed from two child forms,
one that will hold the selected item type (named ``item_type``) and the one that
will hold the selected item ID (named ``item_id``).

Form type class
^^^^^^^^^^^^^^^

``Netgen\ContentBrowser\Form\Type\ContentBrowserDynamicType``

Available options
^^^^^^^^^^^^^^^^^

* ``item_types``

    This option defines which item types will be available to select from

    **type**: ``array`` of ``string`` values, **required**: Yes
