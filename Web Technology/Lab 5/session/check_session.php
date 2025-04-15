<?php
session_start(); // Resume the session
if (isset($_SESSION["username"])) {
    echo "Welcome, " . $_SESSION["username"] . "<br>";
    echo "Roll Number: " . $_SESSION["rollno"] . "<br>";
} else {
    echo "No session found.<br>";
}
echo "<a href='destroy_session.php'>Destroy Session</a>";
