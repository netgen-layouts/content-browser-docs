Upgrading from 1.4.0 to 2.0.0
=============================

Upgrade ``composer.json``
-------------------------

In your ``composer.json`` file, upgrade the version of ``netgen/content-browser``
package and all other related packages (like ``netgen/content-browser-ui``,
``netgen/content-browser-ibexa`` and others) to ``~2.0.0`` and run the
``composer update`` command.

Breaking changes
----------------

* Minimum supported version of PHP is now 8.4

* Minimum supported version of Symfony is now 7.3

* Property hooks and asymmetric visibility have been introduced. This means that
  in ``Netgen\ContentBrowser\Item\ItemInterface`` and
  ``Netgen\ContentBrowser\Item\LocationInterface``, getters have been removed
  and replaced with properties. Rewrite your item and location objects to use
  property hooks.

* ``Netgen\ContentBrowser\Backend\BackendInterface::search`` method has been
  removed in favor of ``searchItems`` method.

* ``Netgen\ContentBrowser\Backend\BackendInterface::searchCount`` method has
  been removed in favor of ``searchItemsCount`` method.

Deprecations
------------

* There were no deprecations in 2.0 version of Netgen Content Browser.
