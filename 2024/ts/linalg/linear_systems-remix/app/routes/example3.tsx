import type { MetaFunction } from "@remix-run/node"
import { Link, Outlet } from "@remix-run/react"

export const meta: MetaFunction = () => {
  return [{ title: "Example 3" }, { name: "description", content: "Linear system equations" }]
}

const exampleUrls = [
  "/example3/plotly",
  "/example3/canvasjs",
  "/example3/observable-plot"
]

export default function Example3() {
  return (
    <div>
      <ul>
        {exampleUrls.map((text) => (
          <Link to={text} key={text}>
            <li>{text}</li>
          </Link>
        ))}
      </ul>
      <Outlet />
    </div>
  )
}
