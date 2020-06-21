import React, { PropTypes } from "react";
//import { geolocated } from "react-geolocated";
//import LocationProvider, { useLocationContext } from "react-geoloc";
import useGeolocation from "react-hook-geolocation";
import Geolocation from "react-geolocation";

//import "./App.css";

const App = () => {
  const geolocation = useGeolocation();
  return (
    <Geolocation
      render={({
        fetchingPosition,
        position: { coords: { latitude, longitude } = {} } = {},
        error,
        getCurrentPosition,
      }) => (
        <div>
          <button onClick={getCurrentPosition}>Get Position</button>
          {error && <div>{error.message}</div>}
          <pre>
            latitude: {latitude}
            longitude: {longitude}
          </pre>
        </div>
      )}
    />
  );
};

export default App;
