Upgrading from 1.3.0 to 1.4.0
=============================

Upgrade ``composer.json``
-------------------------

In your ``composer.json`` file, upgrade the version of ``netgen/content-browser``
package and all other related packages (like ``netgen/content-browser-ui``,
``netgen/content-browser-ibexa`` and others) to ``~1.4.0`` and run the
``composer update`` command.

Changelog
---------

* Added full support for PHP 8.1
* Added PHP 8.x attributes for simplified registering of Symfony services for
  backends and column value providers
* Dropped support for PHP 8.0

Deprecations
------------

* There were no deprecations in 1.4 version of Netgen Content Browser.

Breaking changes
----------------

* There were no breaking changes in 1.4 version of Netgen Content Browser.
