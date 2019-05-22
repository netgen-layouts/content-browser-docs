Usage in JavaScript
===================

Content Browser can be called at will anywhere from your JavaScript code.

Installing the Content Browser plugin
-------------------------------------

Install the JavaScript module:

.. code-block:: console

    $ yarn add https://github.com/netgen-layouts/content-browser-ui#^1.0.0

or

.. code-block:: console

    $ npm install https://github.com/netgen-layouts/content-browser-ui#^1.0.0

Usage
-----

To initialize Content Browser and use it in JavaScript on custom events you can
use the ``Browser`` plugin.

Import and initialize the plugin:

.. code-block:: javascript

    import { Browser } from '@netgen/content-browser-ui';

    // create new Content Browser instance
    const browser = new Browser(config);

    // open the browser
    browser.open();

Plugin accepts JavaScript object as options for that instance. For example:

.. code-block:: javascript

    import { Browser } from '@netgen/content-browser-ui';

    // create new Content Browser instance
    const browser = new Browser({
      overrides: {
        has_preview: false,
        max_selected: 4,
      },
      itemType: 'ezlocation',
      onConfirm: function(selected) {
        // onConfirm function returns selected items
        console.log(selected);
      },
      onCancel: function() {
        console.log('Browser closed');
      },
    });

    // open the browser
    browser.open();


Required parameters for Content Browser config
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* ``itemType``

    Item type to select in the dialog.

    **type**: ``string``

Optional parameters for Content Browser config
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* ``onCancel``

    Function that is called after browser is closed without selecting the items.

    **type**: ``function``

* ``onConfirm``

    Function that is called after selecting the items and confirming in Content Browser.

    Function returns an array of selected items.

    **type**: ``function``

* ``disabledItems``

    Array of item IDs that should be disabled for selection in Content Browser.

    **type**: ``array``

* ``overrides``

    Object with overrides for configuration initially specified via backend
    REST API after opening Content Browser.

    **type**: ``object``
