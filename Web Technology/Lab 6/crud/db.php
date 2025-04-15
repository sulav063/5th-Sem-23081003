<?php
$conn = new mysqli("localhost", "root", "", "lab6");
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
