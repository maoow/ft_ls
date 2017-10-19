# ft_ls
command ft_ls 42 project.
#

## Name
ft_ls - list directory contents

## Synopsys
  ft_ls [option][file]
  
## Description
  List information about the FILEs (the current directory by default).
  Sort entries alphabetically if none of -ftu is specified.
  
###  -a
      do not ignore entries startin with '.'
     
###  -f
      do not sort, enable -a
      
###  -G
      display colors in function of fyletype
      
###  -l
      use a long listing format
  
###  -r
      reverse order while sorting
  
###  -R
      list subdirectories recursively

###  -t
      sort by modification time, newest first

###   -u
      with -lt: sort by, and show, access time; with -l: show access
      time and sort by name; otherwise: sort by access time, newest
      first
