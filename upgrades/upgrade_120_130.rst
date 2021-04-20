Upgrading from 1.2.0 to 1.3.0
=============================

Upgrade ``composer.json``
-------------------------

In your ``composer.json`` file, upgrade the version of ``netgen/content-browser``
package and all other related packages (like ``netgen/content-browser-ui``,
``netgen/content-browser-ezplatform`` and others) to ``~1.3.0`` and run the
``composer update`` command.

Changelog
---------

* Minimum supported PHP version is now 7.4
* Property typehints were added to all properties (private, protected, and
  public) in Netgen Content Browser. Extreme care has been taken to make the
  property hints compatible with previously existing PHPDoc annotations. This
  makes sure that any properly used code from Netgen Content Browser will not
  result in breaking changes.
* Added support for PHP 8. Note that parameter names are not part of the
  backwards compatibility rules. Using PHP 8's named arguments feature might
  break your code when upgrading to newer Content Browser versions.

Deprecations
------------

* There were no deprecations in 1.3 version of Netgen Content Browser.

Breaking changes
----------------

There were no breaking changes in 1.3 version of Netgen Content Browser.
