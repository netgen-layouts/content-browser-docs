Custom backend parameters
=========================

Ibexa location and Ibexa content backends support two custom parameters for now:

* Overriding content types which will be shown in the tree
* Overriding content types which will be selectable

Overriding content types which will be shown in the tree
--------------------------------------------------------

To override which content types will be used to build the location tree, use
``location_content_types`` custom parameter, e.g.:

.. code-block:: html

    <div class="js-input-browse item-empty"
        data-custom-location_content_types="folder,category"
    >
        ...
    </div>

or in case of Twig template usage:

.. code-block:: twig

    {{ include(
        '@NetgenContentBrowser/content_browser.html.twig',
        {
            input_id: 'my-location',
            item_type: 'ibexa_location',
            custom_params: {location_content_types: ['folder', 'category']}
        }
    ) }}

Overriding content types which will be selectable
-------------------------------------------------

To override which content types will be selectable in the list of items, use
``allowed_content_types`` custom parameter, e.g.:

.. code-block:: html

    <div class="js-input-browse item-empty"
        data-custom-allowed_content_types="news,blog_post"
    >
        ...
    </div>

or in case of Twig template usage:

.. code-block:: twig

    {{ include(
        '@NetgenContentBrowser/content_browser.html.twig',
        {
            input_id: 'my-location',
            item_type: 'ibexa_location',
            custom_params: {allowed_content_types: ['news', 'blog_post']}
        }
    ) }}
