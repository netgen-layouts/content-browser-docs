Netgen Content Browser Documentation
====================================

Netgen Content Browser is a Symfony bundle that provides an interface
which selects items from any kind of backend and returns the IDs of
selected items back to the calling code. Main use case is to provide
a way to hook into a CMS backend and select items from the backend
from apps built on top of that same CMS.

For example, Netgen Layouts uses Content Browser to select items which
will be added to block collections.

Out of the box, Netgen Content Browser has the following plugins:

* Selecting content and locations from `Ibexa CMS`_
* Selecting tags from `Netgen Tags Bundle`_ for Ibexa CMS
* Selecting products and taxons from `Sylius eCommerce`_

.. note::

    These plugins have their own separate packages, so if you wish to use
    Content Browser integrated into Ibexa CMS, install and activate
    ``netgen/content-browser-ibexa`` package.

    If you wish to use Content Browser integrated into Sylius, install and
    activate ``netgen/content-browser-sylius`` package.

.. note::

    This documentation assumes you have a working knowledge of the Symfony
    Framework. If you're not familiar with Symfony, please start with
    reading the `Quick Tour`_ from the Symfony documentation.

Reference
---------

.. toctree::
    :hidden:

    reference/index

.. include:: /reference/map.rst.inc

Upgrades
--------

.. toctree::
    :hidden:

    upgrades/index

.. include:: /upgrades/map.rst.inc

The cookbook
------------

:doc:`The cookbook </cookbook/index>` provides a handful of recipes with
which you can learn how to extend and use Netgen Content Browser.

.. toctree::
    :hidden:

    cookbook/index

.. include:: /cookbook/map.rst.inc

Ibexa CMS integration
---------------------

:doc:`This section </ibexa/index>` provides a handful of recipes with
which you can learn how to extend Ibexa CMS integration in Content Browser.

.. toctree::
    :hidden:

    ibexa/index

.. include:: /ibexa/map.rst.inc

.. _`Quick Tour`: https://symfony.com/doc/current/quick_tour
.. _`Ibexa CMS`: https://ibexa.co
.. _`Netgen Tags Bundle`: https://github.com/netgen/tagsbundle
.. _`Sylius eCommerce`: https://sylius.com
