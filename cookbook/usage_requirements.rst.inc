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

    {% include 'NetgenContentBrowserBundle::page_head.html.twig' %}
