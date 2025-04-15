<?php
include('db.php');
// Display all students in ascending order of marks
echo "Students in Ascending Order of Marks:<br>";
$result = $conn->query("SELECT * FROM students ORDER BY marks_obtained ASC");
while ($row = $result->fetch_assoc()) {
    echo "{$row['Student_name']} - {$row['marks_obtained']} - {$row['result']}<br>";
}
// Count students who passed and failed
$pass = $conn->query("SELECT COUNT(*) as count FROM students WHERE result='Pass'")->fetch_assoc();
$fail = $conn->query("SELECT COUNT(*) as count FROM students WHERE result='Fail'")->fetch_assoc();
echo "<br>Total Passed: {$pass['count']}<br>";
echo "Total Failed: {$fail['count']}<br>";
