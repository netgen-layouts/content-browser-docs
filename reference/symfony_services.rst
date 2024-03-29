Available Symfony services
==========================

A number of Symfony services is available for usage in your code:

``netgen_content_browser.registry.backend``
-------------------------------------------

This service is a registry which holds all available backends. It is a class
with ``Netgen\ContentBrowser\Registry\BackendRegistry`` type and you can use
it to manually load Content Browser items by their ID.

.. code-block:: php

    $ibexaLocationBackend = $this->backendRegistry->getBackend('ibexa_location');

    $item = $ibexaLocationBackend->loadItem(42);

Configuration services
----------------------

Every backend has its own configuration service which can be used by the backend
to access all config options specified in Symfony semantic config, as well as
any custom parameters passed to the backend by the calling code. These services
are all instances of ``Netgen\ContentBrowser\Config\Configuration`` class.

The names of these services are ``netgen_content_browser.config.ITEM_TYPE``. So
for ``ibexa_location`` item type, service name would be
``netgen_content_browser.config.ibexa_location``.
