<?php
include('db.php');
// Check if the ID is provided in the URL
if (isset($_GET['id'])) {
    $id = $_GET['id'];
    // Delete the record
    $conn->query("DELETE FROM students WHERE std_id = $id");
    // Redirect to the main page after deletion
    header("Location: edit.php");
    exit();
} else {
    die("Student ID not provided.");
}
