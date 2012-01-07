/*
 * This file is part of the zlog Library.
 *
 * Copyright (C) 2011 by Hardy Simpson <HardySimpson@gmail.com>
 *
 * The zlog Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The zlog Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with the zlog Library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include "zlog.h"

int main(int argc, char** argv)
{
	int rc;
	
	zlog_category_t *a_cat;

	if (argc != 2) {
		printf("test_init ntime\n");
		return -1;
	}

	rc = zlog_init("test_init.conf");
	if (rc) {
		printf("init fail");
		return -2;
	}

	a_cat = zlog_get_category("my_cat");
	if (!a_cat) {
		printf("zlog_get_category fail\n");
		return -1;
	}

	ZLOG_INFO(a_cat, "before update");

	sleep(10);

	rc = zlog_update(NULL);
	if (rc) {
		printf("update fail\n");
	}

	ZLOG_INFO(a_cat, "after update");

	zlog_fini();

# if 0
	rc = zlog_init("zlog.conf");


	k = atoi(argv[1]);
	while (--k > 0) {
		i = rand();
		switch (i % 3) {
		case 0:
			rc = zlog_init("zlog.conf");
			printf("init\n");
			break;
		case 1:
			rc = zlog_update(NULL);
			printf("update\n");
			break;
		case 2:
			zlog_fini();
			printf("fini\n");
	//		printf("zlog_finish\tj=[%d], rc=[%d]\n", j, rc);
			break;
		}
	}


	zlog_fini();

#endif
	
	return 0;
}