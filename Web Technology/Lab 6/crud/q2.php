<?php
include('db.php');
$a = $conn->query("SELECT Student_name, marks_obtained FROM students ORDER BY marks_obtained DESC LIMIT 1")->fetch_assoc();
$b = $conn->query("SELECT Student_name, marks_obtained FROM students ORDER BY marks_obtained ASC LIMIT 1")->fetch_assoc();
$c = $conn->query("SELECT COUNT(*) as total FROM students")->fetch_assoc();
$d = $conn->query("SELECT AVG(marks_obtained) as avg FROM students")->fetch_assoc();
echo "a. Student with Highest Marks: {$a['Student_name']} ({$a['marks_obtained']})<br>";
echo "b. Student with Lowest Marks: {$b['Student_name']} ({$b['marks_obtained']})<br>";
echo "c. Total Number of Students: {$c['total']}<br>";
echo "d. Average Marks: " . round($d['avg'], 2) . "<br>";
?>
