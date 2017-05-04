Configuration reference
=======================

Configuration of Content Browser is done per item type.

To register the new item type in Content Browser, you need to add it to the list
of item types in configuration:

.. code-block:: yaml

    netgen_content_browser:
        item_types:
            my_item_type:
                ...

The following lists all configuration options available in Netgen Content Browser
for every item type:

.. toctree::
    :maxdepth: 3

    configuration/item_types
    configuration/full_example
