Full configuration example
==========================

The following code block shows the full configuration example of an item type
with identifier ``my_item_type``:

.. code-block:: yaml

    netgen_content_browser:
        item_types:
            my_item_type:
                name: item_types.my_item_type
                min_selected: 1
                max_selected: 0
                tree:
                    enabled: true
                search:
                    enabled: false
                preview:
                    enabled: true
                    template: '@App/ngcb/my_item_type.html.twig'
                columns:
                    name:
                        name: columns.name
                        value_provider: name
                    some_column:
                        name: columns.my_item_type.some_column
                        template: '@App/ngcb/my_item_type/some_column.html.twig'
                    other_column:
                        name: columns.my_item_type.other_column
                        value_provider: my_item_type\other_column
                default_columns: [name, some_column]
