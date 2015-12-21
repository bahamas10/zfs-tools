ZFS Tools
=========

Various tools and scripts written for ZFS

Usage
-----

Compile

    make

### `zpool-config`

Dump the output of `zpool_get_config` as JSON to stdout

    $ ./zpool-config zones | json
    {
      "version": 5000,
      "name": "zones",
      "state": 0,
      "txg": 2952044,
      "pool_guid": 4668373440529934000,
      "hostid": 2113612150,
      "hostname": "gz",
      "vdev_children": 1,
      "vdev_tree": {
    ...

License
-------

MIT License
