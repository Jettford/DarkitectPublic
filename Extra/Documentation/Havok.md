# Havok Packfiles 

This is documentation for the non XML, bin Havok physics format

Note: I haven't worked out much yet



## Global Header



**[s32]** Magic 1 (0x57e0e057)

if **[s32]** == 0x10c0c010:

​	**[s32]** Unknown (0x00)

**[u32]** Version

**[s8]** Pointer Length (32 or 64 bit, normally 32)

**[bool]** Little Endian

**[s8]** Reuse Padding Optimization

**[s8]** Empty Base Class Optimization

**[s32]** Section Count

**[s32]** Contents Section Index 
**[s32]** Contents Section Offset 
**[s32]** Contents Class Name Section Index 
**[s32]** Contents Class Name Section Offset 

**[L:16]** Havok Version string

**[L:16]** Padding (0xffffffffffffffff)



## Section

**[L:16]** Section Name

