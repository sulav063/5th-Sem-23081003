<?php
session_start(); // Create/start the session
$_SESSION["username"] = "Sulav Adhikari";
$_SESSION["rollno"] = "23081003";
echo "Session started and values are set.<br>";
echo "<a href='check_session.php'>Go to Check Session Page</a>";
