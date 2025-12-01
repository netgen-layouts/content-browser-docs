PHP attributes for Symfony DI
=============================

The following lists all dependency injection attributes and their usage
available in Netgen Content Browser:

``Netgen\ContentBrowser\Attribute\AsBackend``
---------------------------------------------

**Purpose**: Adds a new backend to the system

A backend is a service that provides methods to load the list of items and
locations in Content Browser interface. A backend needs to implement
``Netgen\ContentBrowser\Backend\BackendInterface`` interface.

When registering a new backend, you need to provide the ``$itemType`` argument
in the attribute to specify the item type the backend is used for.

``Netgen\ContentBrowser\Attribute\AsColumnValueProvider``
---------------------------------------------------------

**Purpose**: Adds a new column value provider for a single item column

A column value provider is a service that provides a value to a column displayed
in Content Browser interface for a specific item. Column value provider needs to
implement
``Netgen\ContentBrowser\Item\ColumnProvider\ColumnValueProviderInterface``
interface.

When registering a new column value provider, you need to provide the
``$identifier`` argument in the attribute to attach a unique identifier to the
provider.
