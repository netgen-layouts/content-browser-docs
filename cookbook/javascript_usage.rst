Usage in JavaScript
===================

Content Browser can be called at will anywhere from your JavaScript code.

Installing the Content Browser plugin
-------------------------------------
Install the javascript module:

.. code-block:: console

    $ yarn add https://github.com/netgen-layouts/content-browser-ui#master

or

.. code-block:: console

    $ npm install https://github.com/netgen-layouts/content-browser-ui#master


Usage
-----
To initialize Content Browser and use it in javascript on custom events you can use ``Browser`` plugin.

Import and initialize the plugin:

.. code-block:: javascript

    import { Browser } from '@netgen/content-browser-ui';

    // create new Content Browser instance
    const browser = new Browser(config);
    // open the browser
    browser.open();

Plugin accepts javascript object as options for that instance.
For example:

.. code-block:: javascript

    import { Browser } from '@netgen/content-browser-ui';

    // create new Content Browser instance
    const browser = new Browser({
      overrides: {
        has_preview: false,
        max_selected: 4,
      },
      rootPath: 'ezlocation',
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


Required parameters for Content Browser config:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* ``rootPath``
    Item type to select in the dialog.

    **type**: ``string``

Optional parameters for Content Browser config:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* ``onCancel``
    Function that is called after browser is closed without selecting items

    **type**: ``function``

* ``onConfirm``
    Function that is called after selecting items and confirming in Content Browser.

    Function returns array of selected items.

    **type**: ``function``

* ``disabledItems``
    Array of item ids that should be disabled in Content Browser

    **type**: ``array``

* ``overrides``
    Object with overrides for config that you get from api after opening Content browser

    **type**: ``object``
