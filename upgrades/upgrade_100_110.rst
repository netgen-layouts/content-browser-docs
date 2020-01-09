Upgrading from 1.0.0 to 1.1.0
=============================

Upgrade ``composer.json``
-------------------------

In your ``composer.json`` file, upgrade the version of ``netgen/content-browser``
package and all other related packages (like ``netgen/content-browser-ui``,
``netgen/content-browser-ezplatform`` and others) to ``~1.1.0`` and run the
``composer update`` command.

Remove unused bundles
---------------------

Netgen Content Browser 1.1 does not depend on WhiteOctober Pagerfanta bundle any
more. If you did not require and use it in your project, it will be
automatically uninstalled. You will need to remove it from your list of
activated bundles manually.

Changelog
---------

* Added support for PHP 7.4
* Added support for Symfony 5

Breaking changes
----------------

There were no breaking changes in 1.1 version of Netgen Content Browser.
