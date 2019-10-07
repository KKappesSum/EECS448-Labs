<?php
  function createTableRow($rowValue){
    echo "<tr>";
    echo "<td>" . $rowValue . "</td>";
    for($k = 1; $k <= 100; $k++){
      echo "<td>" , ($rowValue * $k) , "</td>";
    }
    echo "</tr>";
  }

  function createTable(){
    echo "<table style='font-size: 8pt;'>";
    echo "<tr>";
    for($j = 1; $i <= 100; $i++) {
      echo "<td>" , $i , "</td>";
    }
    echo "</tr>";
    for($j = 1; $j <= 100; $j++){
      createTableRow($j);
    }
    echo "</table>";
  }

  createTable();
?>
