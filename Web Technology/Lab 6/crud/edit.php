<?php
include('db.php');
$result = $conn->query("SELECT * FROM students");
?>
<table border="1">
    <tr>
        <th>ID</th>
        <th>Name</th>
        <th>Roll Number</th>
        <th>Marks</th>
        <th>Result</th>
        <th>Actions</th>
    </tr>
    <?php while($row = $result->fetch_assoc()) { ?>
        <tr>
            <td><?= $row['std_id'] ?></td>
            <td><?= $row['Student_name'] ?></td>
            <td><?= $row['RollNumber'] ?></td>
            <td><?= $row['marks_obtained'] ?></td>
            <td><?= $row['result'] ?></td>
            <td>
                <a href="edit.php?id=<?= $row['std_id'] ?>">Edit</a> |
                <a href="delete.php?id=<?= $row['std_id'] ?>" onclick="return confirm('Are you sure?')">Delete</a>
            </td>
        </tr>
    <?php } ?>
</table>
