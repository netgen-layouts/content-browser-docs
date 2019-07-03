Available Symfony services
==========================

A number of Symfony services is available for usage in your code:

``netgen_content_browser.registry.backend``
-------------------------------------------

This service is a registry which holds all available backends. It is a class
with ``Netgen\ContentBrowser\Registry\BackendRegistry`` type and you can use
it to manually load Content Browser items by their ID.

.. code-block:: php

    $backendRegistry = $this->get('netgen_content_browser.registry.backend');
    $eZLocationBackend = $backendRegistry->getBackend('ezlocation');

    $item = $eZLocationBackend->loadItem(42);

Configuration services
----------------------

Every backend has its own configuration service which can be used by the backend
to access all config options specified in Symfony semantic config, as well as
any custom parameters passed to the backend by the calling code. These services
all implement ``Netgen\ContentBrowser\Config\ConfigurationInterface`` interface.

The names of these services are ``netgen_content_browser.config.ITEM_TYPE``. So
for ``ezlocation`` item type, service name would be
``netgen_content_browser.config.ezlocation``.
