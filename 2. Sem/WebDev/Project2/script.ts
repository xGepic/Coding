function addTableRow() {
  var table: HTMLTableElement = <HTMLTableElement>(
    document.getElementById("myTable")
  );
  var rowCount = table.rows.length;
  var row = table.insertRow(rowCount);

  var cell1 = row.insertCell(0);
  var cell2 = row.insertCell(1);
  var cell3 = row.insertCell(2);
  var cell4 = row.insertCell(3);
  cell1.innerHTML = "NEW CELL1";
  cell2.innerHTML = "NEW CELL2";
  cell3.innerHTML = "NEW CELL3";
  cell4.innerHTML = "NEW CELL4";
}
