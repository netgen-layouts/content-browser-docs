Installation instructions
=========================

Use Composer
------------

Run the following command to install Netgen Content Browser:

.. code-block:: shell

    $ composer require netgen/content-browser

Activate the bundles
--------------------

Activate the Content Browser in your configuration together will all other
required bundles:

.. code-block:: php

    return [
        ...

        Sensio\Bundle\FrameworkExtraBundle\SensioFrameworkExtraBundle::class => ['all' => true],
        Netgen\Bundle\ContentBrowserUIBundle\NetgenContentBrowserUIBundle::class => ['all' => true],
        Netgen\Bundle\ContentBrowserBundle\NetgenContentBrowserBundle::class => ['all' => true],
    ];

Activate the routes
-------------------

Add the following to your routing config to activate Content Browser routes:

.. code-block:: yaml

    netgen_content_browser:
        resource: "@NetgenContentBrowserBundle/Resources/config/routing.yaml"
        prefix: "%netgen_content_browser.route_prefix%"

Install assets
--------------

Run the following from your repo root to install Content Browser assets:

.. code-block:: yaml

    $ php bin/console assets:install --symlink --relative
