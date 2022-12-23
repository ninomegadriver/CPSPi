/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _SELINUX_POLICYCAP_H_
#define _SELINUX_POLICYCAP_H_

/* Policy capabilities */
enum {
	POLICYDB_CAPABILITY_NETPEER,
	POLICYDB_CAPABILITY_OPENPERM,
	POLICYDB_CAPABILITY_EXTSOCKCLASS,
	POLICYDB_CAPABILITY_ALWAYSNETWORK,
	POLICYDB_CAPABILITY_CGROUPSECLABEL,
	POLICYDB_CAPABILITY_NNP_NOSUID_TRANSITION,
	POLICYDB_CAPABILITY_GENFS_SECLABEL_SYMLINKS,
	POLICYDB_CAPABILITY_IOCTL_SKIP_CLOEXEC,
	__POLICYDB_CAPABILITY_MAX
};
#define POLICYDB_CAPABILITY_MAX (__POLICYDB_CAPABILITY_MAX - 1)

extern const char *selinux_policycap_names[__POLICYDB_CAPABILITY_MAX];

#endif /* _SELINUX_POLICYCAP_H_ */
