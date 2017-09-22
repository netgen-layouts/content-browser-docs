Custom preview template for eZ content types
============================================

Implementing custom preview templates for eZ Platform content types is as easy
as adding a new eZ view type in your content view configuration.

For every content type you wish to add the preview for, you need to define an
override template for ``ngcb_preview`` view type, which will then automatically
be used by the Content Browser to display the preview.

For example, to add the preview for your custom content type with identifier
``my_content_type``, add the following config to your eZ Platform config:

.. code-block:: yaml

    ezpublish:
        system:
            default:
                content_view:
                    ngcb_preview:
                        my_content_type:
                            template: '@App/ngcb/preview/my_content_type.html.twig'
                            match:
                                Identifier\ContentType: my_content_type

``@App/ngcb/preview/my_content_type.html.twig`` is then a regular eZ Platform
content view template, meaning you have access to ``content`` and ``location``
variables, which you can use to render what ever you wish.
