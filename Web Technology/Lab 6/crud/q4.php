<?php
include('db.php');
$query = "SELECT s.student_name, s.marks_obtained, d.parent_name, d.email 
FROM students s 
JOIN student_info d ON s.std_id = d.std_id 
WHERE s.result = 'Fail'";
$result = $conn->query($query);
echo "<table border='1' cellpadding='8' cellspacing='0'>";
echo "<tr><th>Student Name</th><th>Marks Obtained</th><th>Parent Name</th><th>Email</th></tr>";
while ($row = $result->fetch_assoc()) {
    echo "<tr>
        <td>{$row['student_name']}</td>
        <td>{$row['marks_obtained']}</td>
        <td>{$row['parent_name']}</td>
        <td>{$row['email']}</td>
    </tr>";
}
echo "</table>";
?>