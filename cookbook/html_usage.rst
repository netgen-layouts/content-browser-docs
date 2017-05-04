Usage in HTML
=============

Content browser can be called at will anywhere from your HTML code by including
a piece of specially crafted HTML.

.. include:: usage_requirements.rst.inc

Calling the Content Browser from your HTML
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Use the following piece of HTML code to call the Content Browser, and replace
the relevant pieces of data to suit your needs (item type, CSS ID for the value
input and ``data-`` attributes).

Take care not to remove or change any other predefined CSS classes or HTML
structure as this will break the content browser dialog.

.. code-block:: html

    <div class="js-input-browse item-empty" data-min_selected="1" data-max_selected="1">
        <div class="input-browse">
            <span class="js-clear"><i class="material-icons">close</i></span>

            <a class="js-trigger" href="#">
                <span class="js-name" data-empty-note="No item selected">Select an item</span>
            </a>
        </div>

        <input type="hidden" class="js-config-name" value="MY_ITEM_TYPE" />
        <input type="hidden" class="js-value" id="VALUE_ID" value="" />
    </div>

Calling the Content Browser from your Twig template
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Alternatively, you can just use a handy Twig template and set the wanted options
via an ``include`` tag:

.. code-block:: jinja

    {% include 'NetgenContentBrowserBundle::content_browser.html.twig'
        with {
            input_id: 'my-location',
            item_type: 'ezlocation',
            value: 42,
            item_name: 'My item',
            no_item_message: 'No item selected',
            required: false,
            min: 2,
            max: 3,
            show_tree: true,
            show_search: false,
            show_preview: true
        }
    %}

The following lists all available parameters that can be transferred to the
template.

Required parameters
^^^^^^^^^^^^^^^^^^^

* ``input_id``

    ID of the input where selected value will be placed, required

    **type**: ``string``

* ``item_type``

    Item type to select in the dialog, required

    **type**: ``string``

Optional parameters
^^^^^^^^^^^^^^^^^^^

* ``value``

    Provides the value to content browser dialog if you already have one

    **type**: ``string``

* ``item_name``

    Item name to render when value is present. If undefined, will fallback to
    the value itself

    **type**: ``string``

* ``no_item_message``

    Message to show if no value is selected

    **type**: ``string``

* ``required``

    If undefined or set to false, will render a button to clear the value

    **type**: ``bool``

* ``min``

    Minimum number of items to select, defaults to configuration if undefined

    **type**: ``int``

* ``max``

    Maximum number of items to select, defaults to configuration if undefined

    **type**: ``int``

* ``show_tree``

    Whether to show the tree or not, defaults to configuration if undefined

    **type**: ``bool``

* ``show_search``

    Whether to show the search or not, defaults to configuration if undefined

    **type**: ``bool``

* ``show_preview``

    Whether to show the preview or not, defaults to configuration if undefined

    **type**: ``bool``
