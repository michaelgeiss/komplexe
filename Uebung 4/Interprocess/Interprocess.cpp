#include "stdafx.h"
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <cstring>
#include <cstdlib>
#include <string>

int main(int count, char *argv[])
{
   using namespace boost::interprocess;

   if(count == 1){  //this is the parent process
	  //if count is 1 the parent process is working
      //shared memory is removed on construction and destruction
      struct sharedmemory_remove
      {
         sharedmemory_remove() { shared_memory_object::remove("SharedMemory"); }
         ~sharedmemory_remove(){ shared_memory_object::remove("SharedMemory"); }
      } remover;

      //Create a shared memory object.
      shared_memory_object shmobject (create_only, "SharedMemory", read_write);

      //Set objectsize
      shmobject.truncate(64);

      //Map the whole shared memory in this process, with this you know exactly where the shared memory is stored
      mapped_region region(shmobject, read_write);

      //Write all the memory to 1
      std::memset(region.get_address(), 1, region.get_size());

      //Launch child process
      std::string s(argv[0]); s += " child ";
      if(0 != std::system(s.c_str()))
         return 1;
   }
   else{
      //Open already created shared memory object.
      shared_memory_object shmobject (open_only, "SharedMemory", read_only);

      //Map the whole shared memory in this process
      mapped_region region(shmobject, read_only);

      //Check that memory was initialized to 1
      char *mem = static_cast<char*>(region.get_address());
      for(std::size_t i = 0; i < region.get_size(); ++i)
         if(*mem++ != 1)
            return 1;   //Error checking memory
   }
   return 0;
}
