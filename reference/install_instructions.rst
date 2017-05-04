Installation instructions
=========================

Use Composer
~~~~~~~~~~~~

Run the following command to install Netgen Content Browser:

.. code-block:: shell

    $ composer require netgen/content-browser

Activate the bundle
~~~~~~~~~~~~~~~~~~~

Activate the Content Browser in your kernel class together will all other
required bundles:

.. code-block:: php

    $bundles = array(
        ...

        new WhiteOctober\PagerfantaBundle\WhiteOctoberPagerfantaBundle(),
        new Sensio\Bundle\FrameworkExtraBundle\SensioFrameworkExtraBundle(),
        new Netgen\Bundle\CoreUIBundle\NetgenCoreUIBundle(),
        new Netgen\Bundle\ContentBrowserBundle\NetgenContentBrowserBundle(),
        new Netgen\Bundle\ContentBrowserUIBundle\NetgenContentBrowserUIBundle(),

        new AppBundle\AppBundle(),
    );

Activate the routes
~~~~~~~~~~~~~~~~~~~

Add the following to your main ``routing.yml`` file to activate Content Browser
routes:

.. code-block:: yaml

    netgen_content_browser:
        resource: "@NetgenContentBrowserBundle/Resources/config/routing.yml"
        prefix: "%netgen_content_browser.route_prefix%"

Install assets
~~~~~~~~~~~~~~

Run the following from your repo root to install Content Browser assets:

.. code-block:: yaml

    $ php app/console assets:install --symlink --relative
