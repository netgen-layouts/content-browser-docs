Upgrading from 1.1.0 to 1.2.0
=============================

Upgrade ``composer.json``
-------------------------

In your ``composer.json`` file, upgrade the version of ``netgen/content-browser``
package and all other related packages (like ``netgen/content-browser-ui``,
``netgen/content-browser-ezplatform`` and others) to ``~1.2.0`` and run the
``composer update`` command.

Changelog
---------

* eZ Platform integration now allows to perform searches in media and users section
* Minimum supported PHP version is now 7.3

Deprecations
------------

* ``BackendInterface::search`` and ``BackendInterface::searchCount`` methods
  are deprecated and will be removed in 2.0. Implement replacement methods
  ``BackendInterface::searchItems`` and ``BackendInterface::searchItemsCount``
  to remove the deprecation. These new methods will be added to the interface
  in 2.0.

  The purpose of the new methods is to provide more stable method signature
  when extending search capabilities of Content Browser planned in future
  versions.

Breaking changes
----------------

There were no breaking changes in 1.2 version of Netgen Content Browser.
