<?php
// a. Create a file named file.txt and open in write mode
$file = fopen("file.txt", "w");
echo nl2br(file_get_contents("test.txt"));
// b. Write name and roll number
fwrite($file, "Name: Sulav Adhikari\n");
fwrite($file, "Roll Number: 23081003\n");
// e. Close the file
fclose($file);
// c. Open the file to read its contents
$file = fopen("file.txt", "r");
$content = fread($file, filesize("file.txt"));
fclose($file);
// d. Add current date to its contents
$currentDate = "Date: " . date("Y-m-d") . "\n";
$content .= $currentDate;
// Write updated content back to the file
$file = fopen("file.txt", "w");
fwrite($file, $content);
fclose($file);
// f. Rename the file to test.txt
rename("file.txt", "test.txt");

