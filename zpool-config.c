/**
 * Dump the output of zpool_get_config as JSON to stdout
 *
 * Author: Dave Eddy <dave@daveeddy.com>
 * Date: December 21, 2015
 * License: MIT
 */

#include <err.h>
#include <stdio.h>

#include <libnvpair.h>
#include <libzfs.h>

int
main(int argc, char **argv)
{
	libzfs_handle_t *zh;
	zpool_handle_t *zp;
	nvlist_t *config;

	if (argc != 2)
		errx(2, "Usage: zpool-config <zpool>");

	if ((zh = libzfs_init()) == NULL)
		err(1, "libzfs_init");

	if ((zp = zpool_open(zh, argv[1])) == NULL)
		err(1, "zpool_open");

	config = zpool_get_config(zp, NULL);
	nvlist_print_json(stdout, config);
	printf("\n");

	zpool_close(zp);
	libzfs_fini(zh);

	return 0;
}
