import dash
from dash import dcc, html
import plotly.graph_objects as go
from metrics_calculator import receive_metrics

# Initialize the Dash app
app = dash.Dash(__name__)

# Create an empty figure
fig = go.Figure()

# Dashboard Layout
app.layout = html.Div([
    html.H1("Market Microstructure Analysis"),
    dcc.Graph(id="order-book-graph", figure=fig),
])

# Update figure with real-time data
@app.callback(
    dash.dependencies.Output("order-book-graph", "figure"),
    dash.dependencies.Input("interval-component", "n_intervals")
)
def update_graph(n):
    # Receive new metrics from the backend
    spread, depth, imbalance = next(receive_metrics())

    # Update graph with the new data
    fig.update_traces(x=[spread], y=[depth], mode='markers')
    return fig

# Run the Dash app
if __name__ == "__main__":
    app.run_server(debug=True, use_reloader=False)

