Implementing a custom column for existing item types
====================================================

Implementing a custom column for existing item types is not any different from
implementing a column for your own custom item type.

The process involves adding a bit of configuration to enable the column:

.. code-block:: yaml

    netgen_content_browser:
        ibexa_location:
            columns:
                my_column:
                    name: columns.ibexa_location.my_column
                    # Either specify a template or a value provider identifier
                    template: '@App/ngcb/ibexa_location/my_column.html.twig'
                    # value_provider: ibexa_location\my_column

And then you need to either create a template that will render the cell of the
column, or create and register a Symfony service that does the same. For more
details, read the relevant sections in the :doc:`chapter about creating a
custom backend </cookbook/custom_backend>`.
