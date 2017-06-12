Requirements
~~~~~~~~~~~~

Before you can use the Content Browser, you need to include its assets
in your page head:

.. code-block:: html+jinja

    <meta name="ngcb-base-path" content="{{ path('ngcb_root') }}">
    <link rel="stylesheet" href="{{ asset('netgen-content-browser.css', 'ngcb_css') }}">
    <script src="{{ asset('netgen-content-browser.js', 'ngcb_js') }}"></script>

or just include the provided Twig template:

.. code-block:: jinja

    {% include '@NetgenContentBrowser/page_head.html.twig' %}

All HTML code blocks which have ``js-input-browse`` CSS class will be automatically initialized
on document ready with jQuery and the plugin which are included in ``netgen-content-browser.js``.

If you use another CSS class, or if you add content browser HTML code via AJAX to your page,
you will need to manually initialize the plugin on those elements:

.. code-block:: javascript

    // ngc_jquery variable holds jQuery included with Netgen Content Browser
    ngc_jquery('.js-input-browse').input_browse();
