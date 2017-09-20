Upgrading from 0.8.0 to 0.9.0
=============================

Upgrade ``composer.json``
-------------------------

In your ``composer.json`` file, upgrade the version of ``netgen/content-browser``
package to ``~0.9.0`` and run the ``composer update`` command.

Breaking changes
----------------

The following breaking changes were made in version ``0.9`` of Content Browser.
Follow the instructions to upgrade your code to this newer version.

* Many services that should not be used directly and are not part of public API
  are now marked as private in service container. Remove usage of those services
  in your code.

* Most of the internal ``protected`` dependencies and methods were made
  ``private``. Rather than extending internal classes, you need to use other
  patterns when changing built in behaviour.
