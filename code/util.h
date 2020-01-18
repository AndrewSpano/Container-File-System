#ifndef __UTIL__
#define __UTIL__

#include "structs.h"

#define MAX_BUFFER_SIZE 512

/* useful functions */
int get_nth_string(char* str, const char buf[], int n);
int get_option(const char buffer[]);

/* navigation functions */
size_t* pointer_to_offset(char* pointer, size_t fns);
char* pointer_to_next_name(char* pointer, size_t fns);

/* initialization functions */
void initialize_superblock(superblock* my_superblock, char* cfs_filename, int fd, size_t root_directory_offset, size_t current_size, size_t bs, size_t fns, size_t cfs, uint mdfn);
void initialize_holes(hole_map* holes, uint n, uint current_holes, size_t hole_start);
void initialize_MDS(MDS* mds, uint id, uint type, uint number_of_hard_links, uint blocks_using, size_t size, size_t parent_offset, size_t first_block);
void initialize_Directory_Data_Block(Block* block, size_t fns, size_t self_offset, size_t parent_offset);

/* printing functions */
void print_superblock(superblock* my_superblock);
void print_hole_table(hole_map* holes);
void print_MDS(MDS* mds);
void print_Directory_Data_Block(Block* block, size_t fns);

#endif
