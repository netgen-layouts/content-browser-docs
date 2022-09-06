Requirements
------------

Before you can use the Content Browser, you need to include its assets
in your page head:

.. code-block:: twig

    <meta name="ngcb-base-path" content="{{ path('ngcb_root') }}">
    <link rel="stylesheet" href="{{ asset('main.css', 'ngcb_css') }}">
    <script src="{{ asset('main.js', 'ngcb_js') }}"></script>

or just include the provided Twig template:

.. code-block:: twig

    {{ include('@NetgenContentBrowser/page_head.html.twig') }}

All HTML code blocks which have ``js-input-browse`` or ``js-multiple-browse``
CSS class will be automatically initialized on window load with the included
JavaScript code.

If you use another CSS class, or if you wish to add Content Browser markup via
AJAX to your page, you will need to manually initialize the plugin on those
elements. In that case, you don't have to include JavaScript assets in your
page head. Instead, you will need to install Content Browser via Yarn/NPM and
import the plugin in your own JavaScript code manually.

Content Browser JavaScript module was preinstalled for you when you installed
Content Browser via Composer. Activate it in your setup with:

.. code-block:: console

    $ yarn add file:vendor/netgen/content-browser-ui

or

.. code-block:: console

    $ npm install file:vendor/netgen/content-browser-ui

Import and initialize the Content Browser plugin:

.. code-block:: javascript

    import { InputBrowse, MultipleBrowse } from '@netgen/content-browser-ui';

    // initialize single item select plugin
    [...document.getElementsByClassName('js-input-browse')].forEach(el => new InputBrowse(el));

    // initialize multiple item select plugin
    [...document.getElementsByClassName('js-multiple-browse')].forEach(el => new MultipleBrowse(el));
