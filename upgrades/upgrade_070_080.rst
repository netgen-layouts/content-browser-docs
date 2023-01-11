Upgrading from 0.7.0 to 0.8.0
=============================

Upgrade ``composer.json``
-------------------------

In your ``composer.json`` file, upgrade the version of ``netgen/content-browser``
package to ``~0.8.0`` and run the ``composer update`` command.

Breaking changes
----------------

The following breaking changes were made in version ``0.8`` of Content Browser.
Follow the instructions to upgrade your code to this newer version.

* ``sections`` config has been removed from configuration of item types since
  overriding sections has never been properly implemented. Remove the section
  from your own item type definitions.

* The concept of item serializer handlers is removed. Previously, they were used
  to specify how certain data will be serialized for an item. One method that
  the ``Netgen\ContentBrowser\Item\Serializer\ItemSerializerHandlerInterface``
  provided has been moved to ``Netgen\ContentBrowser\Item\ItemInterface``, so
  you need to move your implementation there:

  .. code-block:: php

      // Before

      <?php

      namespace App\ContentBrowser\Item\Serializer\Handler;

      use Netgen\ContentBrowser\Item\ItemInterface;
      use Netgen\ContentBrowser\Item\Serializer\ItemSerializerHandlerInterface;

      class MyItemSerializerHandler implements ItemSerializerHandlerInterface
      {
          /**
           * Returns if the item is selectable.
           *
           * @param \Netgen\ContentBrowser\Item\ItemInterface $item
           *
           * @return bool
           */
          public function isSelectable(ItemInterface $item)
          {
              // Determine if the item is selectable
          }
      }

  .. code-block:: php

      // After

      <?php

      namespace App\ContentBrowser\Item\MyItem;

      use Netgen\ContentBrowser\Item\ItemInterface;

      class Item implements ItemInterface
      {
          /**
           * Returns if the item is selectable.
           *
           * @return bool
           */
          public function isSelectable()
          {
              // Determine if the item is selectable
          }
      }

* The concept of item template value providers is removed. Previously, they were
  used to provide the variables that will be used by the templates to render the
  item preview and columns. Now, one single variable called ``item`` is injected
  to all Twig templates. This variable holds the actual item which is rendered,
  which means that your ``Netgen\ContentBrowser\Item\ItemInterface`` objects
  need to provide everything that will be used to render the templates.

  .. code-block:: php

      // Before

      <?php

      namespace App\ContentBrowser\Item\Renderer\TemplateValueProvider;

      use Netgen\ContentBrowser\Item\ItemInterface;
      use Netgen\ContentBrowser\Item\Renderer\TemplateValueProviderInterface;

      class MyItemTemplateValueProvider implements TemplateValueProviderInterface
      {
          /**
           * Provides the values for template rendering.
           *
           * @param \Netgen\ContentBrowser\Item\ItemInterface $item
           *
           * @return array
           */
          public function getValues(ItemInterface $item)
          {
              $thingOne = ...;
              $thingTwo = ...;

              return array(
                  'thingOne' => $thingOne,
                  'thingTwo' => $thingTwo,
              );
          }
      }

  .. code-block:: php

      // After

      <?php

      namespace App\ContentBrowser\Item\MyItem;

      use Netgen\ContentBrowser\Item\ItemInterface;

      class Item implements ItemInterface
      {
          /**
           * Returns thing one.
           *
           * @return mixed
           */
          public function getThingOne()
          {
              return ...;
          }

          /**
           * Returns thing two.
           *
           * @return mixed
           */
          public function getThingTwo()
          {
              return ...;
          }
      }

  In your templates, instead of directly using variables ``thingOne`` and
  ``thingTwo``, you will now use ``item.thingOne`` and ``item.thingTwo``.
