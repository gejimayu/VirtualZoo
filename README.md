![title](https://cloud.githubusercontent.com/assets/25560419/25236645/924ae134-2612-11e7-847a-23f64a2c71b9.png)

*****************************************
**   Virtual Zoo VZ03 - Demo version   **<br>
**            Made by : AC             **<br>
**     Kevin Jonathan - 13515052       **<br>
**    Albertus Djauhari - 13515054     **<br>
**    Gianfranco Fertino - 13515118    **<br>
**     Lazuardi Firdaus - 13515136     **<br>
*****************************************<br>

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!<br>
                          ATTENTION!!!!<br>
            This version has only been tested on UNIX.<br>
We are not responsible for incompatibility for other Operating System<br>
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!<br>


********************<br>
 HOW TO RUN PROGRAM<br>
********************<br>
1. Make sure you have ncurses library before compiling. You can download it from http://invisible-island.net/ncurses/#downloads. For Ubuntu user :
	sudo apt-get install libncurses-dev

2. Make sure you have Google Test library. Download it here https://github.com/google/googletest. For Ubuntu user :
	sudo apt-get install libgtest-dev
	sudo apt-get install cmake
	cd /usr/src/gtest
	sudo cmake CMakeLists.txt
	sudo make
	sudo cp *.a /usr/lib
 
3. Open terminal (for UNIX) or command prompt (for Windows), open current directory using
	cd directory_path

4. Run command
	make

5. There will be an executable file called Main. Run it in terminal
	./Main
   or command prompt
	Main

6. Enjoy your visit in the Virtual Zoo

7. The Test executable file is a unit test file using google test. To run it in terminal use 
	./Test
   or command prompt
	Test

![title](https://cloud.githubusercontent.com/assets/25560419/25236650/94e8aaf2-2612-11e7-8eea-1ebf53377c0a.png)
![title](https://cloud.githubusercontent.com/assets/25560419/25236653/96758188-2612-11e7-8f6c-d83009119af0.png)
![title](https://cloud.githubusercontent.com/assets/25560419/25236656/97c2dfd6-2612-11e7-9b30-44fcee9672f1.png)


*******************************
 HOW TO GENERATE DOCUMENTATION
*******************************
1. Download Doxygen http://www.stack.nl/~dimitri/doxygen/download.html. For Ubuntu user run command
	sudo apt-get install doxygen

2. Open terminal (for UNIX) or command prompt (for Windows), open current directory using
	cd directory_path

3. Run command
	doxygen Doxyfile

4. There will be a folder named Documentation. Open it. Inside, open folder html and search index.html, open it.

5. The complete documentation for this project is all yours.
