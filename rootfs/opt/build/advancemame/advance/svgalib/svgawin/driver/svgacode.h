#ifndef __SVGACODE_H
#define __SVGACODE_H

/** 
 * Version of the SVGALIB interface. 
 */
#define SVGALIB_VERSION 0x01020000

#define FILE_DEVICE_SVGALIB 0x00008000

typedef struct {
	ULONG port;
	ULONG size;
} SVGALIB_PORT_READ_IN;

typedef struct {
	ULONG data;
} SVGALIB_PORT_READ_OUT;

typedef struct {
	ULONG port;
	ULONG size;
	ULONG data;
} SVGALIB_PORT_WRITE_IN;

typedef struct {
	ULONG bus;
} SVGALIB_PCI_BUS_OUT;

typedef struct {
	ULONG bus_device_func;
	ULONG offset;
	ULONG size;
} SVGALIB_PCI_READ_IN;

typedef struct {
	ULONG data;
} SVGALIB_PCI_READ_OUT;

typedef struct {
	ULONG bus_device_func;
	ULONG size;
	ULONG offset;
	ULONG data;
} SVGALIB_PCI_WRITE_IN;

typedef struct {
	PHYSICAL_ADDRESS address; /* Bus-relative address */
	ULONG bus; /* Bus number */
	ULONG size; /* Length of section to map */
} SVGALIB_MAP_IN;

typedef struct {
	VOID* address;
} SVGALIB_MAP_OUT;

typedef struct {
	VOID* address;
} SVGALIB_UNMAP_IN;

typedef struct {
	ULONG version;
} SVGALIB_VERSION_OUT;

#define SVGALIB_IOCTL_INDEX 0x800

#define IOCTL_SVGALIB_MAP CTL_CODE(FILE_DEVICE_SVGALIB, SVGALIB_IOCTL_INDEX+0, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_UNMAP CTL_CODE(FILE_DEVICE_SVGALIB, SVGALIB_IOCTL_INDEX+1, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_PORT_READ CTL_CODE(FILE_DEVICE_SVGALIB, SVGALIB_IOCTL_INDEX+2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_PORT_WRITE CTL_CODE(FILE_DEVICE_SVGALIB, SVGALIB_IOCTL_INDEX+3, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_PCI_BUS CTL_CODE(FILE_DEVICE_SVGALIB, SVGALIB_IOCTL_INDEX+4, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_PCI_READ CTL_CODE(FILE_DEVICE_SVGALIB, SVGALIB_IOCTL_INDEX+5, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_PCI_WRITE CTL_CODE(FILE_DEVICE_SVGALIB, SVGALIB_IOCTL_INDEX+6, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_GIVEIO_ON CTL_CODE(FILE_DEVICE_SVGALIB, SVGALIB_IOCTL_INDEX+7, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_GIVEIO_OFF CTL_CODE(FILE_DEVICE_SVGALIB, SVGALIB_IOCTL_INDEX+8, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_TOTALIO_ON CTL_CODE(FILE_DEVICE_SVGALIB, SVGALIB_IOCTL_INDEX+9, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_TOTALIO_OFF CTL_CODE(FILE_DEVICE_SVGALIB, SVGALIB_IOCTL_INDEX+10, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_VERSION CTL_CODE(FILE_DEVICE_SVGALIB, SVGALIB_IOCTL_INDEX+11, METHOD_BUFFERED, FILE_ANY_ACCESS)

/* 
 * Wrapper for the IOCTL_VIDEO_* functionality. 
 * The documentation is at :
 * http://msdn.microsoft.com/library/default.asp?url=/library/en-us/graphics/hh/graphics/virqs_2raf.asp
 */

typedef struct _SVGALIB_MODE_INFORMATION {
	ULONG Length;
	ULONG ModeIndex;
	ULONG VisScreenWidth;
	ULONG VisScreenHeight;
	ULONG ScreenStride;
	ULONG NumberOfPlanes;
	ULONG BitsPerPlane;
	ULONG Frequency;
	ULONG XMillimeter;
	ULONG YMillimeter;
	ULONG NumberRedBits;
	ULONG NumberGreenBits;
	ULONG NumberBlueBits;
	ULONG RedMask;
	ULONG GreenMask;
	ULONG BlueMask;
	ULONG AttributeFlags;
	ULONG VideoMemoryBitmapWidth;
	ULONG VideoMemoryBitmapHeight;
	ULONG DriverSpecificAttributeFlags;
} SVGALIB_MODE_INFORMATION;

typedef struct _SVGALIB_MEMORY {
	VOID* RequestedVirtualAddress;
} SVGALIB_MEMORY;

typedef struct _SVGALIB_SHARE_MEMORY {
	HANDLE ProcessHandle;
	ULONG ViewOffset;
	ULONG ViewSize;
	VOID* RequestedVirtualAddress;
} SVGALIB_SHARE_MEMORY;

typedef struct _SVGALIB_SHARE_MEMORY_INFORMATION {
	ULONG SharedViewOffset;
	ULONG SharedViewSize;
	VOID* VirtualAddress;
} SVGALIB_SHARE_MEMORY_INFORMATION;

typedef struct _SVGALIB_PUBLIC_ACCESS_RANGES {
	ULONG InIoSpace;
	ULONG MappedInIoSpace;
	VOID* VirtualAddress;
} SVGALIB_PUBLIC_ACCESS_RANGES;

#define IOCTL_SVGALIB_SAVE_HARDWARE_STATE CTL_CODE(FILE_DEVICE_SVGALIB, 0x80, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_RESTORE_HARDWARE_STATE CTL_CODE(FILE_DEVICE_SVGALIB, 0x81, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_QUERY_AVAIL_MODES CTL_CODE(FILE_DEVICE_SVGALIB, 0x100, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_QUERY_NUM_AVAIL_MODES CTL_CODE(FILE_DEVICE_SVGALIB, 0x101, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_QUERY_CURRENT_MODE CTL_CODE(FILE_DEVICE_SVGALIB, 0x102, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_SET_CURRENT_MODE CTL_CODE(FILE_DEVICE_SVGALIB, 0x103, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_RESET_DEVICE CTL_CODE(FILE_DEVICE_SVGALIB, 0x104, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_LOAD_AND_SET_FONT CTL_CODE(FILE_DEVICE_SVGALIB, 0x105, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_SET_PALETTE_REGISTERS CTL_CODE(FILE_DEVICE_SVGALIB, 0x106, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_SET_COLOR_REGISTERS CTL_CODE(FILE_DEVICE_SVGALIB, 0x107, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_ENABLE_CURSOR CTL_CODE(FILE_DEVICE_SVGALIB, 0x108, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_DISABLE_CURSOR CTL_CODE(FILE_DEVICE_SVGALIB, 0x109, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_SET_CURSOR_ATTR CTL_CODE(FILE_DEVICE_SVGALIB, 0x10a, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_QUERY_CURSOR_ATTR CTL_CODE(FILE_DEVICE_SVGALIB, 0x10b, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_SET_CURSOR_POSITION CTL_CODE(FILE_DEVICE_SVGALIB, 0x10c, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_QUERY_CURSOR_POSITION CTL_CODE(FILE_DEVICE_SVGALIB, 0x10d, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_ENABLE_POINTER CTL_CODE(FILE_DEVICE_SVGALIB, 0x10e, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_DISABLE_POINTER CTL_CODE(FILE_DEVICE_SVGALIB, 0x10f, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_SET_POINTER_ATTR CTL_CODE(FILE_DEVICE_SVGALIB, 0x110, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_QUERY_POINTER_ATTR CTL_CODE(FILE_DEVICE_SVGALIB, 0x111, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_SET_POINTER_POSITION CTL_CODE(FILE_DEVICE_SVGALIB, 0x112, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_QUERY_POINTER_POSITION CTL_CODE(FILE_DEVICE_SVGALIB, 0x113, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_QUERY_POINTER_CAPABILITIES CTL_CODE(FILE_DEVICE_SVGALIB, 0x114, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_GET_BANK_SELECT_CODE CTL_CODE(FILE_DEVICE_SVGALIB, 0x115, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_MAP_SVGALIB_MEMORY CTL_CODE(FILE_DEVICE_SVGALIB, 0x116, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_UNMAP_SVGALIB_MEMORY CTL_CODE(FILE_DEVICE_SVGALIB, 0x117, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_QUERY_PUBLIC_ACCESS_RANGES CTL_CODE(FILE_DEVICE_SVGALIB, 0x118, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_FREE_PUBLIC_ACCESS_RANGES CTL_CODE(FILE_DEVICE_SVGALIB, 0x119, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SVGALIB_QUERY_COLOR_CAPABILITIES CTL_CODE(FILE_DEVICE_SVGALIB, 0x11a, METHOD_BUFFERED, FILE_ANY_ACCESS)

#endif

