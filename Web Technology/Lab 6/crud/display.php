<?php include "db.php"; ?>
<!DOCTYPE html>
<html>
<head>
    <title>Students Result</title>
</head>
<body>
    <h2>Students List</h2>
    <table border="1" cellpadding="8">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Roll Number</th>
            <th>Marks</th>
            <th>Result</th>
            <th>Actions</th>
        </tr>
        <?php
        $result = $conn->query("SELECT * FROM students LIMIT 5");
        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                    <td>{$row['std_id']}</td>
                    <td>{$row['Student_name']}</td>
                    <td>{$row['RollNumber']}</td>
                    <td>{$row['marks_obtained']}</td>
                    <td>{$row['result']}</td>
                    <td>
                        <a href='edit.php?id={$row['std_id']}'>Edit</a> |
                        <a href='delete.php?id={$row['std_id']}'
                        onclick=\"return confirm('Are you sure?');\">Delete</a>
                    </td>
                </tr>";
        }
        ?>
    </table>
</body>
</html>