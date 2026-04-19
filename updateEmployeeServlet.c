package cse5c8;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;

import javax.servlet.http.*;

@WebServlet(&quot;/updateEmployeeServlet&quot;)
public class UpdateEmployeeServlet extends HttpServlet {

protected void doGet(HttpServletRequest request, HttpServletResponse response)
throws ServletException, IOException {

response.setContentType(&quot;text/plain&quot;);
PrintWriter out = response.getWriter();

try {
String eidStr = request.getParameter(&quot;eid&quot;);
String name = request.getParameter(&quot;ename&quot;);
String salaryStr = request.getParameter(&quot;salary&quot;);
String ageStr = request.getParameter(&quot;age&quot;);

int eid = Integer.parseInt(eidStr);
int salary = Integer.parseInt(salaryStr);
int age = Integer.parseInt(ageStr);

Employee e = new Employee();
e.setEid(eid);
e.setEname(name);
e.setSalary(salary);
e.setAge(age);

EmployeeDAO dao = new EmployeeDAO();
int result = dao.updateEmployee(e);

if (result &gt; 0) {
out.println(&quot;Employee Updated Successfully\n&quot;);
} else {
out.println(&quot;Employee Not Found\n&quot;);
}
out.println(&quot;Database selected: 5c8&quot;);
out.println(&quot;Updated Employee Table:&quot;);
out.println(&quot;EID | ENAME | SALARY | AGE&quot;);
for (Employee emp : dao.getAllEmployees()) {
out.println(
emp.getEid() + &quot; | &quot; +
emp.getEname() + &quot; | &quot; +
emp.getSalary() + &quot; | &quot; +
emp.getAge()
);
}

} catch (Exception e) {
out.println(&quot;Error: &quot; + e.getMessage());
}
}
}
