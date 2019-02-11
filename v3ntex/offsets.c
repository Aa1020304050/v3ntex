//
//  offsets.c
//  v3ntex
//
//  Created by tihmstar on 23.01.19.
//  Copyright © 2019 tihmstar. All rights reserved.
//

#include "offsets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dprintf printf
#define dstrcmp strcmp

t_offsets *guoffsets = NULL;
//typedef struct{
//    kptr_t offset_zone_map;
//    kptr_t offset_kernel_map;
//    kptr_t offset_kernel_task;
//    kptr_t offset_realhost;
//    kptr_t offset_bzero;
//    kptr_t offset_bcopy;
//    kptr_t offset_copyin;
//    kptr_t offset_copyout;
//    kptr_t offset_ipc_port_alloc_special;
//    kptr_t offset_ipc_kobject_set;
//    kptr_t offset_ipc_port_make_send;
//    kptr_t offset_rop_ldr_r0_r0_0xc;
//    kptr_t offset_chgproccnt;
//    kptr_t offset_kauth_cred_ref;
//    kptr_t offset_OSSerializer_serialize;
//    kptr_t offset_ipc_space_is_task;
//    kptr_t offset_task_itk_self;
//    kptr_t offset_task_itk_registered;
//    kptr_t offset_vtab_get_external_trap_for_index;
//    kptr_t offset_iouserclient_ipc;
//    kptr_t offset_proc_ucred;
//    kptr_t offset_task_bsd_info;
//    kptr_t offset_sizeof_task;
//}t_offsets;

t_offsets *info_to_target_environment(char *uname) {
    guoffsets = NULL;
    t_offsets uoffsets;
    int pushing = 0;
#define pushOffset(off) *(((kptr_t*)&uoffsets)+(pushing++)) = (off)
    if (!dstrcmp(uname, "Darwin Kernel Version 17.4.0: Fri Dec  8 19:35:52 PST 2017; root:xnu-4570.40.9~1/RELEASE_ARM64_S5L8960X")){
//        pushOffset(0x80476220); //zone_map
//        pushOffset(0x804ac034); //kernel_map
//        pushOffset(0x804ac030); //kernel_task
//        pushOffset(0x804611b0); //realhost
//        pushOffset(0x80009168); //bzero
//        pushOffset(0x80008e1d); //bcopy
//        pushOffset(0x80007a64); //copyin
//        pushOffset(0x80007b4c); //copyout
//        pushOffset(0x8001a1ab); //ipc_port_alloc_special
//        pushOffset(0x8002c399); //ipc_kobject_set
//        pushOffset(0x80019d59); //ipc_port_make_send
//        pushOffset(0x801160b9); //rop_ldr_r0_r0_0xc
//        pushOffset(0x8029b979); //chgproccnt
//        pushOffset(0x8027b03b); //kauth_cred_ref
//        pushOffset(0x80346345); //OSSerializer_serialize
//        pushOffset(0x00000018); //ipc_space_is_task
//        pushOffset(0x000000a4); //task_itk_self
//        pushOffset(0x000001e4); //task_itk_registered
//        pushOffset(0x000000e1); //vtab_get_external_trap_for_index
//        pushOffset(0x00000060); //iouserclient_ipc
//        pushOffset(0x00000090); //proc_ucred
//        pushOffset(0x00000238); //task_bsd_info
//        pushOffset(0x000003d8); //sizeof_task
    }
    else{
        dprintf("[!] Failed to load offsets\n");
        return NULL;
    }
    
    guoffsets = malloc(sizeof(t_offsets));
    memcpy(guoffsets,&uoffsets,sizeof(t_offsets));
    
    dprintf("[*] Loaded offsets:\n");
    dprintf("    0x%016llx -offset_zone_map\n",uoffsets.offset_zone_map);
    dprintf("    0x%016llx -offset_kernel_map\n",uoffsets.offset_kernel_map);
    dprintf("    0x%016llx -offset_kernel_task\n",uoffsets.offset_kernel_task);
    dprintf("    0x%016llx -offset_realhost\n",uoffsets.offset_realhost);
    dprintf("    0x%016llx -offset_bzero\n",uoffsets.offset_bzero);
    dprintf("    0x%016llx -offset_bcopy\n",uoffsets.offset_bcopy);
    dprintf("    0x%016llx -offset_copyin\n",uoffsets.offset_copyin);
    dprintf("    0x%016llx -offset_copyout\n",uoffsets.offset_copyout);
    dprintf("    0x%016llx -offset_ipc_port_alloc_special\n",uoffsets.offset_ipc_port_alloc_special);
    dprintf("    0x%016llx -offset_ipc_kobject_set\n",uoffsets.offset_ipc_kobject_set);
    dprintf("    0x%016llx -offset_ipc_port_make_send\n",uoffsets.offset_ipc_port_make_send);
    dprintf("    0x%016llx -offset_rop_ldr_r0_r0_0xc\n",uoffsets.offset_rop_ldr_r0_r0_0xc);
    dprintf("    0x%016llx -offset_chgproccnt\n",uoffsets.offset_chgproccnt);
    dprintf("    0x%016llx -offset_kauth_cred_ref\n",uoffsets.offset_kauth_cred_ref);
    dprintf("    0x%016llx -offset_OSSerializer_serialize\n",uoffsets.offset_OSSerializer_serialize);
    dprintf("    0x%016llx -offset_ipc_space_is_task\n",uoffsets.offset_ipc_space_is_task);
    dprintf("    0x%016llx -offset_task_itk_self\n",uoffsets.offset_task_itk_self);
    dprintf("    0x%016llx -offset_task_itk_registered\n",uoffsets.offset_task_itk_registered);
    dprintf("    0x%016llx -offset_vtab_get_external_trap_for_index\n",uoffsets.offset_vtab_get_external_trap_for_index);
    dprintf("    0x%016llx -offset_iouserclient_ipc\n",uoffsets.offset_iouserclient_ipc);
    dprintf("    0x%016llx -offset_proc_ucred\n",uoffsets.offset_proc_ucred);
    dprintf("    0x%016llx -offset_task_bsd_info\n",uoffsets.offset_task_bsd_info);
    dprintf("    0x%016llx -offset_sizeof_task\n",uoffsets.offset_sizeof_task);
    
    return guoffsets;
}
