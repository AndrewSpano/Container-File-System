#ifndef __STRUCTS__
#define __STRUCTS__

#define MAX_HOLES 1000
#define PERMS 0777
#define _XOPEN_SOURCE 700
#define READ_WRITE_USER_GROUP_PERMS 0660


#define LINK 0
#define DIRECTORY 1
#define FILE 2

#define MAX_CFS_FILENAME_SIZE 30
#define MAX_DIGITS 15

#define DEFAULT_BLOCK_SIZE 512
#define DEFAULT_FNS 30
#define DEFAULT_CFS 4096
#define DEFAULT_MDFN 69

#define PRINT_HIERARCHY 5



#include "time.h"

typedef unsigned int uint;
typedef unsigned char byte;
typedef unsigned long long ull;

typedef struct hole
{
  off_t start;
  off_t end;
} hole;


typedef struct hole_map
{
  long unsigned int current_hole_number;
  hole holes_table[MAX_HOLES];
} hole_map;


typedef struct
{
  uint id;
  uint type;
  uint number_of_hard_links;
  uint blocks_using;

  size_t size;
  off_t parent_offset;
  off_t first_block;

  time_t creation_time;
  time_t access_time;
  time_t modification_time;
} MDS;


typedef struct pair
{
  char* name;
  off_t offset;
} pair;

typedef struct Block
{
  off_t next_block;
  size_t bytes_used;
  byte data[];
} Block;



typedef struct superblock
{
  uint fd;
  char cfs_filename[MAX_CFS_FILENAME_SIZE];

  uint total_entities;
  off_t root_directory;
  size_t current_size;
  size_t block_size;
  size_t filename_size;
  size_t max_file_size;
  uint max_dir_file_number;
} superblock;




#endif
