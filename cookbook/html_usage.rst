Usage in HTML
=============

Content browser can be called at will anywhere from your HTML code by including
a piece of specially crafted HTML.

.. include:: usage_requirements.rst.inc

Calling the Content Browser from your HTML
------------------------------------------

Use the following piece of HTML code to call the Content Browser, and replace
the relevant pieces of data to suit your needs (item type, CSS ID for the value
input and ``data-`` attributes).

After you select some items and close the Content Browser dialog, selected value
will be available in a hidden input with a ``js-value`` CSS class.

Take care not to remove or change any other predefined CSS classes or HTML
structure as this will break the Content Browser dialog.

``data-`` attributes are all optional. ``data-`` attributes modify the behaviour
of the interface, like limiting the number of items which can be selected, or
showing/hiding certain aspects of the interface. One special ``data-`` attribute
is used to modify the behaviour of the backend, by transferring it to the
backend via query parameters. Basically, every ``data-`` attribute which starts
with ``data-custom-``, will be transferred to the backend so you can use it to
modify the behaviour as you see fit. In the backend, you can inject the
configuration object, as explained in
:doc:`the list of available Symfony services </reference/symfony_services>`,
which will then hold the list of all custom parameters.

.. tip::

    To help you reach the selected value, you can attach custom CSS ID to hidden
    input where value is stored, as shown below.

.. code-block:: html

    <div class="js-input-browse item-empty"
        data-min_selected="1"
        data-max_selected="1"
        data-start_location="42"
    >
        <div class="input-browse">
            <span class="js-clear"><i class="material-icons">close</i></span>

            <a class="js-trigger" href="#">
                <span class="js-name" data-empty-note="No item selected">Select an item</span>
            </a>
        </div>

        <input type="hidden" class="js-item-type" value="MY_ITEM_TYPE" />
        <input type="hidden" class="js-value" id="CSS_ID" value="" />
    </div>

Calling the Content Browser from your Twig template
---------------------------------------------------

Alternatively, you can just use a handy Twig template and set the wanted options
via an ``include`` tag:

.. code-block:: twig

    {% include '@NetgenContentBrowser/content_browser.html.twig'
        with {
            input_id: 'my-location',
            item_type: 'ezlocation',
            item_name: 'My item',
            no_item_message: 'No item selected',
            required: false,
            min: 2,
            max: 3,
            custom_params: {param1: 'value1', param2: ['value2', 'value3']},
            start_location: 42,
            show_tree: true,
            show_search: false,
            show_preview: true
        }
    %}

The following lists all available parameters that can be transferred to the
template.

Required parameters
~~~~~~~~~~~~~~~~~~~

* ``input_id``

    ID of the input where selected value will be placed, required

    **type**: ``string``

* ``item_type``

    Item type to select in the dialog, required

    **type**: ``string``

Optional parameters
~~~~~~~~~~~~~~~~~~~

* ``item_name``

    Item name to render when you already have a value

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

* ``custom_params``

    The list of custom parameters to transfer to the backend

    **type**: ``array``

* ``start_location``

    This option defines in which location the Content Browser will start

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
