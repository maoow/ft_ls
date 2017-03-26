		flags="1R"
		flags1="l"
		flags2="tu"
		flags3="f"
		flags4="a"
		flags5="lu"
		path=".."
		path1="/Applications "
		path2="/nfs/2013 /nfs/2014 /nfs/2015 /nfs/event"
		path3="/Users"
		path4="/etc" 
		path5="/private "
		path6="/Library "
		path7="/Network "
		path8="/System "
		path9="/sbin "
   		path10="/sgoinfre "
		path11="/var"
		path12="/usr"
		path13="/Volumes "
		path14="/bin "
		path15="/cdn"
		path16="/cores "
		path17="/dev "
		path18="/goinfre" 
		path19="/home " 
		path20="/installer.failurerequests" 
		path21="/net " 
		path22="/opt" 

		make

		sleep 1

	echo "ls -"$flags $path2
	ls -$flags $path2 > output1ls 2> output2ls
	./ft_ls -$flags $path2 > output1ft 2> output2ft
	cut -c4- output2ft > output2ft2
	wc -l output1ls output2ls
	wc -l output1ft output2ft 
	sort output2ft2 > output2sft
	sort output2ls > output2sls
	diff output1ft output1ls >diffs
	diff output2sft output2sls >diff2
	cat diffs diff2
	rm -f output1ft output1ls output1sls output2ft output2ft2 output2ls outputs1ft outputs1ls outputs2ft output2sft output2sls




	echo "\n\nls -"$flags2 $path
	ls -$flags2 $path > output1ls 2> output2ls
	./ft_ls -$flags2 $path > output1ft 2> output2ft
	cut -c4- output2ft > output2ft2
	wc -l output1ls output2ls
	wc -l output1ft output2ft 
	diff output1ft output1ls >diffs
	diff output2ft output2ls >diff2
	cat diffs diff2
	rm -f output1ft output1ls output1sls output2ft output2ft2 output2ls outputs1ft outputs1ls outputs2ft output2sft output2sls


	echo "\n\nls -"$flags3 $path17
	ls -$flags3 $path17 > output1ls 2> output2ls
	./ft_ls -$flags3 $path17 > output1ft 2> output2ft
	cut -c4- output2ft > output2ft2
	wc -l output1ls output2ls
	wc -l output1ft output2ft 
	diff output1ft output1ls >diffs
	diff output2ft output2ls >diff2
	cat diffs diff2
	rm -f output1ft output1ls output1sls output2ft output2ft2 output2ls outputs1ft outputs1ls outputs2ft output2sft output2sls



	echo "\n\nls -"$flags4 $path17
	ls -$flags4 $path17 > output1ls 2> output2ls
	./ft_ls -$flags4 $path17 > output1ft 2> output2ft
	cut -c4- output2ft > output2ft2
	wc -l output1ls output2ls
	wc -l output1ft output2ft 
	diff output1ft output1ls >diffs
	diff output2ft output2ls >diff2
	cat diffs diff2
	rm -f output1ft output1ls output1sls output2ft output2ft2 output2ls outputs1ft outputs1ls outputs2ft output2sft output2sls



	echo "\n\nls -"$flags4 $path17/*
	ls -$flags4 $path17/* > output1ls 2> output2ls
	./ft_ls -$flags4 $path17/* > output1ft 2> output2ft
	cut -c4- output2ft > output2ft2
	wc -l output1ls output2ls
	wc -l output1ft output2ft 
	diff output1ft output1ls >diffs
	diff output2ft output2ls >diff2
	cat diffs diff2
	rm -f output1ft output1ls output1sls output2ft output2ft2 output2ls outputs1ft outputs1ls outputs2ft output2sft output2sls



	echo "\n\nls -"$flags5 $path2
	ls -$flags5 $path2 > output1ls 2> output2ls
	./ft_ls -$flags5 $path2 > output1ft 2> output2ft
	cut -c4- output2ft > output2ft2
	wc -l output1ls output2ls
	wc -l output1ft output2ft 
	diff output1ft output1ls >diffs
	diff output2ft output2ls >diff2
	cat diffs diff2
	rm -f output1ft output1ls output1sls output2ft output2ft2 output2ls outputs1ft outputs1ls outputs2ft output2sft output2sls



	echo "\n\nls -"$flags1 $path17
	ls -$flags1 $path17 > output1ls 2> output2ls
	./ft_ls -$flags1 $path17 > output1ft 2> output2ft
	cut -c4- output2ft > output2ft2
	wc -l output1ls output2ls
	wc -l output1ft output2ft 
	diff output1ft output1ls >diffs
	diff output2ft output2ls >diff2
	cat diffs diff2
	rm -f output1ft output1ls output1sls output2ft output2ft2 output2ls outputs1ft outputs1ls outputs2ft output2sft output2sls

	rm -f output1ft output1ls output1sft output2ft output2ls diff2 diffs
